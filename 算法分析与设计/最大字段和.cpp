int MaxSum(int a[],int left,int right)
{
	int sum=0,midsum=0,leftsum=0,rightsum=0;
	int center,s1,s2,lefts,rights;
	if(left==right)
	{
		sum=a[left];
	}
	else{
		center=(left+right)/2;
		leftsum=MaxSum(a,left,center);
		rightsum=MaxSum(a,center+1,right);
		s1=0;lefts=0;
		for(int i=center;i>=left;i--)
		{
			lefts+=a[i];
			if(lefts>s1){
				s1=lefts;
			}
		}
		s2=0;rights=0;
		for(int j=center+1;j<=right;j++)
		{
			rights+=a[i];
			if(rights>s2){
				s2=rights;
			}
		}
		midsum=s1+s2;
		if(midsum<leftsum)
		{
			sum=leftsum;
		}
		else{
			sum=midsum;
		}
		if(sum<rightsum)
		{
			sum=rightsum;
		}
	}
	return sum;
}

