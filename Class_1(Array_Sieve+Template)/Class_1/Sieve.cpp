//#include <iostream>
//
//int main(void)
//{
//	// ??????? ?????? ?????, ??????? ??????? ?? ???? ? ?? 1. ????? ?? ??????? ? ??????????? ?????? ????? ? ????? ???. (2.4.6.8.10.12.14.16.18.20.22..)
//	// ??????? ????. ????????????? ?????, ??????? ??????? ?? ???? ? ?? 1. ??? ?? ????? ?? ??????? ? ??????????? ?????? ????? ? ????? 3 
//	// ?????? (3,6,9,12,15,18,21,24,27,30..) ????? ?????? ?? ?? ????, ? ?? ???????? ????? ?????. (x*x) ?.?. ?????????? ????????? ????? ??? ??????????.
//	// ???? ????????????? ????? ???????, 5 ? ??????????? ??? 5 (10,15,20,25,30).
//	// ???? ?? ??? ??? ???? ????. ??????? ????? ? ???????? ?????? ??? ???????????? ????? ???????. 
//	// ?????? 7*7=49, ??? ?????? ??? 30.
//	int n;
//	std::cin >> n;
//
//	bool sieve[100 + 1];
//	
//	for (int i = 2; i < n +1; i++) // 0 ? 1 ?? ???????, ??????? ? 2-?
//	{
//		sieve[i] = true; // ??? ????? ??????? ??????????.
//	}
//
//	int x=2; // ?????????? ?? ??????? ???? ??????.
//	while (x * x <= n)
//	{
//		if (sieve[x]) // ???? x ???????? ???????, ????????? ???.
//		{
//			for (int y = x*x; y <= n; y+=x) // ???????? ?? ???, ?? ?? ?????? ?? ???????, ??????????? ??? ?? ???
//			{
//				sieve[y] = false; // ?????????.
//			}
//		}
//		x += 1;
//	}
//
//	for (int x = 2; x < n + 1; x++)
//	{
//		if (sieve[x])
//			std::cout << x << '\t';
//	}
//	std::cout << '\n';
//}