class Node {
   public:
    string data;
    Node* next;
    Node* prev;

    Node(string url) {
        this->data = url;
        prev = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
   private:
    Node* currentPage;

   public:
    BrowserHistory(string homepage) { currentPage = new Node(homepage); }

    void visit(string url) {
        Node* newPage = new Node(url);
        currentPage->next = newPage;
        newPage->prev = currentPage;
        currentPage = newPage;
    }

    string back(int steps) {
        while (steps) {
            if (currentPage->prev) {
                currentPage = currentPage->prev;
            } else {
                break;
            }

            steps--;
        }

        return currentPage->data;
    }

    string forward(int steps) {
        while (steps) {
            if (currentPage->next) {
                currentPage = currentPage->next;
            } else {
                break;
            }

            steps--;
        }

        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */