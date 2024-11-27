#pragma once
#include <string>
#include <ctime>
#include <type_traits>

template <typename URLType = std::string, typename TimeType = time_t>
class BrowserTab
{
private:
	struct Node
	{
		URLType url;
		TimeType timestamp;
		Node* next;
		Node* prev;

		Node(const URLType& url = "about:blank")
			: url(url), timestamp(-1), next(nullptr), prev(nullptr) {}

	};

	Node* currentTab = new Node("about:blank");
	Node* head = currentTab;
	Node* tail = currentTab;

	void copyFrom(const BrowserTab& data);
	void moveFrom(BrowserTab&& data);
	void free();
public:
	BrowserTab() = default;
	BrowserTab(const BrowserTab& data);
	BrowserTab(BrowserTab&& data);

	BrowserTab& operator=(const BrowserTab& data);
	BrowserTab& operator=(BrowserTab&& data);
	~BrowserTab();

	void go(const std::string currentURLOfTab);

	void insert(const URLType& newURL);

	void back();

	void forward();

	void remove();

	void sortByURL();

	void BrowserTab<URLType, TimeType>::sortByTime();

	void BrowserTab<URLType, TimeType>::insertionSortOnBrowser(Node* tabs, size_t size);

	void print();

};

template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::free()
{
	while (currentTab)
	{
		Node* toDelete = currentTab;
		currentTab = currentTab->next;
		delete toDelete;
	}

	currentTab = new Node("about:blank");
	head = currentTab;
	tail = currentTab;
}

template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::copyFrom(const BrowserTab& data)
{
	free();

	if (!data.head)
	{
		head = tail = currentTab = new Node("about:blank");
		return;
	}

	Node* otherIter = data.head;
	while (otherIter)
	{
		insert(otherIter->url);
		otherIter = otherIter->next;
	}
}

template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::moveFrom(BrowserTab&& data)
{
	free();

	if (!data.head)
	{
		head = tail = currentTab = new Node("about:blank");
		return;
	}

	head = data.head;
	tail = data.tail;
	currentTab = data.currentTab;

	data.head = data.tail = data.currentTab = nullptr;

	/*Node* newCurrentBrowserTab = head;

	while (newCurrentBrowserTab)
	{
		Node* toDelete = data.currentTab;
		newCurrentBrowserTab->next = data.currentTab;
		newCurrentBrowserTab->next = data.currentTab->next;
		newCurrentBrowserTab->prev = data.currentTab->prev;
		data.currentTab = data.currentTab->next;
		delete toDelete;
	}

	data.head = data.tail = data.currentTab = nullptr;*/
}

template <typename URLType, typename TimeType>
BrowserTab<URLType, TimeType>::BrowserTab(const BrowserTab& data)
{
	copyFrom(data);
}

template <typename URLType, typename TimeType>
BrowserTab<URLType, TimeType>::BrowserTab(BrowserTab&& data)
{
	moveFrom(std::move(data));
}

template <typename URLType, typename TimeType>
BrowserTab<URLType, TimeType>& BrowserTab<URLType, TimeType>::operator=(const BrowserTab& data)
{
	if (this != &data)
	{
		copyFrom(data);
	}

	return *this;
}

template <typename URLType, typename TimeType>
BrowserTab<URLType, TimeType>& BrowserTab<URLType, TimeType>::operator=(BrowserTab&& data)
{
	if (this != &data)
	{
		moveFrom(data);
	}

	return *this;
}

template <typename URLType, typename TimeType>
BrowserTab<URLType, TimeType>::~BrowserTab()
{
	free();
}

//Командата зарежда страницата с URL <url> в текущия таб.
//Автоматично трябва да се обнови timestamp - а на таба.
template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::go(const std::string currentURLOfTab)
{
	if (currentTab->url == "about:blank")
	{
		head = tail = currentTab = new Node(currentURLOfTab);
	}

	Node* current = head;
	while (current)
	{
		if (current->url == currentURLOfTab) 
		{
			currentTab = current;
			currentTab->timestamp = time(nullptr);
			break;
		}
		current = current->next;
	}
	
}

//Добавя нов таб след текущия, в който се зарежда страницата с URL <url>.
//За този нов таб автоматично се обновява неговия timestamp.Новият таб става текущ.
template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::insert(const URLType& newURL)
{
	if (newURL == "")
	{
		return;
	}

	Node* newTab = new Node(newURL);
	newTab->timestamp = time(nullptr);
	
	currentTab = head;
	while (currentTab->next)
	{
		currentTab = currentTab->next;
	}
	currentTab->next = newTab;
	newTab->prev = currentTab;
	newTab->next = nullptr;
	currentTab = newTab;
}

//Потребителят се прехвърля на таба, който е непосредствено преди текущия.
//Ако такъв няма(т.е.в момента сме върху първия таб), не се случва нищо.
template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::back()
{
	if (!currentTab)
	{
		head = tail = currentTab = new Node("about:blank");
		return;
	}

	if (currentTab->prev)
	{
		currentTab = currentTab->prev;
	}
}

//Браузърът отива на таба, който е непосредствено след текущия.
//Ако такъв няма (т.е. в момента сме върху последния таб), не се случва нищо.
template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::forward()
{
	if (!currentTab)
	{
		head = tail = currentTab = new Node("about:blank");
		return;
	}

	if (currentTab->next)
	{
		currentTab = currentTab->next;
	}
}

//Премахва текущия таб.Текущ става този след него.Ако такъв няма, текущ става този преди него.
//Ако това е бил единственият отворен таб, се отваря нов и в него се зарежда адрес “about : blank”.
template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::remove()
{
	if (!head)
	{
		head = tail = this->currentTab = new Node("about:blank");
		return;
	}

	if (head == tail && head == currentTab)
	{
		delete currentTab;
		head = tail = this->currentTab = new Node("about:blank");
		return;
	}

	Node* temp = head;

	while (temp)
	{
		if (currentTab == temp)
		{
			Node* toDelete = currentTab;
			if (!currentTab->prev)
			{
				this->currentTab = currentTab->next;
				head = this->currentTab;
			}
			else if (!currentTab->next)
			{
				this->currentTab = currentTab->prev;
				tail = this->currentTab;
			}
			else
			{
				this->currentTab = (currentTab->next) ? currentTab->next : currentTab->prev;
			}
			

			delete toDelete;
			break;
		}
		temp = temp->next;
	}
}

template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::sortByURL()
{
	if (!head || head->next)
	{	
		return;
	}

	Node* current = head;

	while (current)
	{
		if(strcmp(current))
	}
}

template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::insertionSortOnBrowser(Node* tabs, const size_t size)
{
	Node* arrOfTabs = new Node[size];
	Node* current = tabs;

	for (size_t i = 0; i < length; i++)
	{
		arrOfTabs[i] = current;
		current = current->next;
	}

	for (int i = 1; i < size; i++)
	{
		int currentIndex = i - 1;
		TimeType currentTime = arrOfTabs[i]->timestamp;
		Node* currentTimeNext = arrOfTabs[i]->next;
		Node* currentTimePrev = arrOfTabs[i]->prev;

		while (currentIndex >= 0 && arrOfTabs[i]->timestamp > currentTime)
		{
			arrOfTabs[i]->next = arrOfTabs[i]->next->next;
			arrOfTabs[i]->next->next->pre; = arrOfTabs[i];

			arrOfTabs[i + 1]->next = arrOfTabs[i];
			arrOfTabs[i + 1]->prev = arrOfTabs[i]->prev;
			arrOfTabs[i]->prev->next = arrOfTabs[i + 1];
			arrOfTabs[i]->prev = arrOfTabs[i + 1];
			currentIndex--;
		}
	}

	

	delete arrOfTabs;
}

/*int currentIndex = i - 1;
		TimeType currentTime = (&tabs[i])->timestamp;
		Node* temp = &tabs[i];
		while (currentIndex >=0 && &tabs[currentIndex]->timestamp > currentTime)
		{
			&tabs[currentIndex + 1]->prev->next = &tabs[currentIndex]->next;
			&tabs[currentIndex + 1]->next->prev = &tabs[currentIndex]->next->next->prev;
			&tabs[currentIndex + 1]->timestamp = &tabs[currentIndex]->timestamp;
			currentIndex--;
		}
		&tabs[currentIndex + 1]->timestamp = currentTime;*/

template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::sortByTime()
{
	if (!head)
	{
		head = tail = this->currentTab = new Node("about:blank");
		return;
	}

	Node* current = head;
	unsigned size = 1;
	while (current != tail)
	{
		size++;
		current = current->next;
	}

	insertionSortOnBrowser(head, size);
	
}

//Извежда на екрана всички табове. Форматът е следния: 
//<URL> <timestamp>
//(Между двата елемента има един интервал)
//Редът, на който се намира текущият таб, трябва да започва със знак за по - голямо(> ), например:
//> www.example.com 123456789
//Страниците да се извеждат точно в реда, в който се пазят в браузъра.
template <typename URLType, typename TimeType>
void BrowserTab<URLType, TimeType>::print()
{
	Node* current = head;

	if (!current)
	{
		head = tail = currentTab = new Node("about:blank");
	}

	while (current)
	{
		if (current == currentTab)
		{
			std::cout << "> " << current->url << ' ' << current->timestamp << std::endl;
		}
		else
		{
			std::cout << current->url << ' ' << current->timestamp << std::endl;
		}

		current = current->next;
	}
}