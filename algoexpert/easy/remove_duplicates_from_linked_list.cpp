//
// Created by Süleyman Karakaşoğlu on 25.08.2022.
//
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {

    LinkedList* prev = nullptr;
    LinkedList* prevNonDuplicate = nullptr;
    auto currentNode = linkedList;
    while (currentNode) {
        if (prev) {
            if (prev->value == currentNode->value) {
                if (!prevNonDuplicate) {
                    prevNonDuplicate = prev;
                }

                if (!currentNode->next) {
                    prevNonDuplicate->next = nullptr;
                }
            } else if (prevNonDuplicate) {
                prevNonDuplicate->next = currentNode;
                prevNonDuplicate = nullptr;
            }
        }

        prev = currentNode;
        currentNode = currentNode->next;
    }

    return linkedList;
}
