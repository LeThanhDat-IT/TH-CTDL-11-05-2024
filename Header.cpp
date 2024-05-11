#include "Header.h"

#include "Header.h"

int length(NODEPTR head) {
	int count = 0;
	while (head) {
		count++;
		head = head->next;
	}
	return count;
}

void menu(NODEPTR& head) {
	do {
		int choose, key, idx, pos;
		cout << "\n0. Thoat chuong trinh";
		cout << "\n1. Khoi tao danh sach";
		cout << "\n2. Tao node them vao dau";
		cout << "\n3. Tao node them vao cuoi";
		cout << "\n4. Xuat danh sach";
		cout << "\n5. Xuat danh sach dao nguoc";
		cout << "\n6. Them gia tri vao sau q";
		cout << "\n7. Them gia tri vao truoc q";
		cout << "\n8. Them gia tri vao vi tri";
		cout << "\n---------------> Chon chuc nang: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			init(head);
			break;
		case 2:
			createNodeFirst(head);
			break;
		case 3:
			createNodeLast(head);
			break;
		case 4:
			cout << endl;
			outputNode(head);
			cout << endl;
			break;
		case 5:
			cout << endl;
			outputNodeReverse(head);
			cout << endl;
			break;
		case 6:

			cout << "\nNhap vao gia tri them vao sau: ";
			cin >> idx;
			cout << "\nNhap vao gia tri: ";
			cin >> key;
			if (findNode(head, idx) == NULL) {
				cout << "\nKhong tim thay gia tri " << idx << endl;
			}
			else {
				addAfterMid(findNode(head, idx), key);
				cout << "\nThem gia tri " << key << " thanh cong !!!!" << endl;
			}
		case 7:
			cout << "\nNhap vao gia tri them vao truoc: ";
			cin >> idx;
			cout << "\nNhap vao gia tri: ";
			cin >> key;
			if (findNode(head, idx) == NULL) {
				cout << "\nKhong tim thay gia tri " << idx << endl;
			}
			else {
				addBeforeMid(findNode(head, idx), key);
				cout << "\nThem gia tri " << key << " thanh cong !!!!" << endl;
			}
		case 8:
			cout << "\nNhap vao vi tri: ";
			cin >> pos;
			cout << "\nNhap vao gia tri: ";
			cin >> key;
			insertA(head, key, pos);
		case 9:
			cout << "Enter data for the new node: ";
			cin >> data;
			addNode(head, data);
			break;
		default:
			break;
		}
	} while (true);
}

//Khởi tạo
void init(NODEPTR& head) {
	head = NULL;
}

//Tạo node
NODEPTR makeNode(TYPEINFO x) {
	NODEPTR p = new NODE;
	if (p == NULL) return NULL;
	p->info = x;
	p->next = p->prev = NULL;
	return p;
}

//Tìm node
NODEPTR findNode(NODEPTR head, TYPEINFO x) {
	while (head) {
		if (head->info == x) {
			return head;
		}
		else {
			head = head->next;
		}
	}
	return NULL;
}

//Kiểm tra có rỗng hay không
bool isEmpty(NODEPTR head) {
	return head == NULL;
}

//Thêm vào đầu
void addFirst(NODEPTR& head, TYPEINFO x) {
	NODEPTR p = makeNode(x);
	if (isEmpty(head) == true) {
		head = p;
	}
	else {
		p->next = head;
		head->prev = p;
		head = p;
	}
}

//Thêm vào cuối
void addLast(NODEPTR& head, TYPEINFO x) {
	NODEPTR p = makeNode(x);
	if (isEmpty(head) == true) {
		head = p;
	}
	else {
		NODEPTR r;
		for (r = head; r->next != NULL; r = r->next);
		r->next = p;
		p->prev = r;
	}

}

//Thêm vào giữa
void addAfterMid(NODEPTR q, TYPEINFO x) {
	NODEPTR p = makeNode(x);

	p->next = q->next;
	q->next = p;
	p->next->prev = p;
	p->prev = q;
}

//Thêm vào giữa trước node
void addBeforeMid(NODEPTR q, TYPEINFO x) {
	NODEPTR p = makeNode(x);
	*p = *q;
	q->next = p;
	p->prev->next = p;
	p->prev = q;
	q->info = x;
}

//Thêm vào vị trí
void insertA(NODEPTR& head, TYPEINFO x, int pos) {
	if (pos < 0 || pos > length(head)) {
		throw "Pos is incorrect";
	}
	if (pos == 0) {
		addFirst(head, x);
	}
	else if (pos == length(head)) {
		addLast(head, x);
	}
	else {
		NODEPTR r;
		int count = 0;
		for (r = head, count = 0; count < pos; count++, r = r->next)
		addBeforeMid(r, x);
	}
}

void createNodeFirst(NODEPTR& head) {
	int x;
	do {
		cout << "\n Enter a number (0: Exit) : ";
		cin >> x;
		if (x == 0) break;
		addFirst(head, x);
	} while (true);
}

void createNodeLast(NODEPTR& head) {
	int x;
	do {
		cout << "\n Enter a number (0: Exit) : ";
		cin >> x;
		if (x == 0) break;
		addLast(head, x);
	} while (true);
}

void outputNode(NODEPTR head) {
	while (head) {
		cout << head->info << "\t";
		head = head->next;
	}
}

void outputNodeReverse(NODEPTR head) {
	NODEPTR r;
	for (r = head; r->next != NULL; r = r->next);
	while (r) {
		cout << r->info << "\t";
		r = r->prev;
	}
}

void addNode(NODEPTR& head, TYPEINFO data) {
	NODEPTR newNode = new NODE;
	newNode->info = data;
	newNode->next = nullptr;

	if (head == nullptr) {
		// If the list is empty, set the new node as the head
		newNode->prev = nullptr;
		head = newNode;
	}
	else {
		// Find the last node in the list
		NODEPTR current = head;
		while (current->next != nullptr) {
			current = current->next;
		}

		// Set the new node's prev pointer to the last node
		newNode->prev = current;
		// Update the last node's next pointer to the new node
		current->next = newNode;
	}
}
