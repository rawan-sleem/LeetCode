// Time  O(n)
// Space  O(n)
class BrowserHistory {
private:
    stack<string> s1, s2;

public:
    BrowserHistory(string homepage) {
        // Constructor to initialize the browser history with a homepage
        s1.push(homepage);
    }
    
    void visit(string url) {
        // Function to visit a new URL
        s1.push(url);
        // Clear the forward history since a new visit invalidates forward history
        while (!s2.empty()) {
            s2.pop();
        }
    }
    
    string back(int steps) {
        // Function to navigate back 'steps' times in history
        while (s1.size() > 1 && steps > 0) {
            string temp = s1.top();
            s1.pop();
            s2.push(temp); // Move the visited URLs to the forward history stack
            steps--;
        }
        return s1.top(); // Return the current URL after navigating back
    }
    
    string forward(int steps) {
        // Function to navigate forward 'steps' times in history
        while (!s2.empty() && steps > 0) {
            string temp = s2.top();
            s2.pop();
            s1.push(temp); // Move the URLs from forward history back to main history stack
            steps--;
        }
        return s1.top(); // Return the current URL after navigating forward
    }
};

