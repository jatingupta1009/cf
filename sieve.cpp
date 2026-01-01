vector <int> sieve(int n)
{
	vector <int> prime;
	vector <int> sie(n+1,1);
	for(int i=2;i*i<=n;i++)
	{
		if(sie[i]==0)continue;
		for(int j=2*i;j<=n;j+=i)
			sie[j]=0;
	}
	for(int i=2;i<=n;i++)
		if(sie[i])
			prime.push_back(i);
	return prime;
}
