// Sortable_list.h
template <class Record>
class Sortable_list : public List<Record>
{
public:
	void quick_sort();

protected:
	//  Add prototypes for auxiliary functions here
	Node<Record> *divide_from(Node<Record> *&sub_list, Node<Record> *&pivot);
	void recursive_quick_sort(Node<Record> *&head, Node<Record> *tail);
};

template <class Record>
Node<Record> *Sortable_list<Record>::divide_from(Node<Record> *&sub_list, Node<Record> *&pivot)
{
	Node<Record> dummy_low, dummy_high;
	Node<Record> *current = sub_list->next,
				 *temp;
	// traverse entire list and send to its sublist
	while (current != NULL)
	{
		temp = current->next;
		if (current->entry <= pivot->entry)
		{
			current->next = dummy_low.next;
			dummy_low.next = current;
		}
		else
		{
			current->next = dummy_high.next;
			dummy_high.next = current;
		}
		current = temp;
	}
	sub_list = dummy_low.next;
	pivot->next = NULL;
	return dummy_high.next ;
}

template <class Record>
void Sortable_list<Record>::recursive_quick_sort(Node<Record> *&sub_list, Node<Record> *tail)
{
	if (sub_list != NULL && sub_list->next != NULL)
	{
		Node<Record> *pivot = sub_list;
		cout << "Pivot chosen : " << pivot->entry << endl;
		Node<Record> *second_half = divide_from(sub_list, pivot);
		Node<Record> *tail1 = NULL, *tail2 = NULL, *temp = sub_list;
		cout << "sub_list: ";
		while (temp != NULL)
		{
			cout << temp->entry << " ";
			tail1 = temp;
			temp = temp->next;
		}
		cout << endl;

		if (sub_list != NULL)
			recursive_quick_sort(sub_list, tail1);

		temp = second_half;
		cout << "\nsecond_half: ";
		while (temp != NULL)
		{
			tail2 = temp;
			temp = temp->next;
		}
		cout << endl;
		if (second_half != NULL)
			recursive_quick_sort(second_half, tail2);

		if (sub_list == NULL)
		{ //low list is empty
			cout << "low list is empty\n";
			cout << "Pivot : " << pivot->entry << endl;
			sub_list = pivot;
			pivot->next = second_half;
			temp = second_half;
			while (temp != NULL)
			{
				tail2 = temp;
				temp = temp->next;
			}
			tail = tail2;
		}
		else if (second_half == NULL)
		{
			 // high list is empty
			cout << "high list is empty "<<pivot->entry<<endl;
			temp = sub_list;
			while (temp != NULL)
			{
				tail1 = temp;
				temp = temp->next;
			}
			tail1->next = pivot;
		}
		else
		{ // both not empty, regular case
			cout << "both lists are not empty\n";
			temp = sub_list;
			while (temp != NULL)
			{
				tail1 = temp;
				temp = temp->next;
			}
			tail1->next = pivot;
			pivot->next = second_half;
		}
		Node<Record> *temp23 = this->head;
		cout<<endl;
		while (temp23 != NULL)
		{
			cout << temp23->entry << " ";
			temp23 = temp23->next;
		}
		cout<<endl;
	}
}

template <class Record>
void Sortable_list<Record>::quick_sort()

{
	Node<Record> *tail = this->head;
	while (tail->next != nullptr)
	{
		tail = tail->next;
	}
	recursive_quick_sort(this->head, tail);
	Node<Record> *temp = this->head;
	cout << endl;
	while (temp != NULL)
	{
		cout << temp->entry << " ";
		temp = temp->next;
	}
}
