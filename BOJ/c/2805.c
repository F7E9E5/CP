#include <stdio.h>
#include <stdlib.h>

int height[1000001];

int compare(const int *a, const int *b) {
	return (*a > *b) ? 1 : (*a < *b) ? -1 : 0;
}

int main() {
	int i, N, M;
	scanf("%d %d", &N, &M); /*������ ��, ��ǥ ���� ����*/
	for (i = 0; i < N; i++) scanf("%d", &height[i]);
		
	qsort(height, N, sizeof(int), 
		 (int(*)(const void *, const void *))compare);
	
	/*�̺� Ž���� ���� ��ǥ ���� ���̸� �����ϴ� ���̸� ã�´�.
	�� ���̰� �ִ� ���̰� �ƴ� �� �����Ƿ� ����ؼ� �̺� Ž����
	���������ν� �ִ� ���̸� ã�´�.*/
    unsigned long long sum, start = 0, end = height[N - 1], result;
	while (start <= end) {
		sum = 0;
		unsigned long long mid = (start + end) / 2;     //� ���̰� ������ �����ϴ��� ��� 
		for (i = 0; i < N; i++) {
			if (height[i] > mid) 
				sum += height[i] - mid;
		}
		
		if (sum >= M) { 		    //���� ������ �����Ѵٸ� �ִ� ���̸� ã�´�. 
			result = mid;
			start = mid + 1; 
		} 
		else end = mid - 1;	    //������ �������� ���Ѵٸ� ���̸� ���߾� ã�´�. 
	}	
	
	printf("%lld", result);
	
	return 0;
}
