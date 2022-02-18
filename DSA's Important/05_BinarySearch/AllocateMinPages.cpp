/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1/

#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &books, int students, int currMin){
	int N = books.size();
	int studentCnt = 1, curStudent = 0;

		for (int i = 0; i < N; i++){

			if (books[i] > currMin) return false;
			
			if (curStudent + books[i] > currMin){
				studentCnt++;
				curStudent = books[i];

				if (studentCnt > students)
					return false;
			}

			else{
				curStudent += books[i];
			}
		}

	return true;
}

int minPages(vector<int> &books, int students){
	int N = books.size();
	int start = 0, end = 0;

		for (int &book: books){
			start = min(book, start);
			end += book;
		}

	int result = INT_MAX;

		while (start <= end){
			int currMin = (start + end) / 2;

			if (isPossible(books, students, currMin)){
				result = min(result, currMin);
				end = currMin - 1;
			}else {
				start = currMin + 1;
			}
		}

	return result;
}

int32_t main(){
	// write the code here
	vector<int> books{13, 31, 37, 45, 46, 54, 55, 63, 73, 84, 85};
	int students{9};

		cout << minPages(books, students);

	return 0;
}
