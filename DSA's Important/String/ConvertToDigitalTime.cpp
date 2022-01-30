/*
    यावद्बध्दो मरुद देहे यावच्चित्तं निराकुलम्।
    यावद्द्रॄष्टिभ्रुवोर्मध्ये तावत्कालभयं कुत: ॥
*/

/*
	INPUT
	-----
	61 

	OUTPUT
	------
	1:01
*/

#include <bits/stdc++.h>

using namespace std;

string convert_to_digital_time(int minutes){
	int hours;
	
		hours = minutes / 60;
		minutes %= 60;

	string strHours = to_string(hours);
	string strMinutes = to_string(minutes);

		if (strMinutes.length() == 1) strMinutes = "0" + strMinutes;

	return strHours + ":" + strMinutes;
}

int32_t main(){
	// write the code here
	int minutes; cin >> minutes;
		cout << convert_to_digital_time(minutes) << endl;
	return 0;
}
