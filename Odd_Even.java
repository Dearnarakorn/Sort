class Odd_Even{
	public static void oddEvenSort(int arr[]){
		int n = arr.length;
		boolean isSorted = false; // Initially array is unsorted
		while (!isSorted){
			isSorted = true;
			int temp =0;
			// Perform Bubble sort on odd indexed element
			for (int i=1; i<=n-2; i=i+2){
				if (arr[i] > arr[i+1]){
					temp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = temp;
					isSorted = false;
				}
			}
			// Perform Bubble sort on even indexed element
			for (int i=0; i<=n-2; i=i+2){
				if (arr[i] > arr[i+1])
				{
					temp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = temp;
					isSorted = false;
				}
			}
		}
	}

	public static void main (String[] args)
	{
		int arr[] = {34, 2, 10, -9};

		oddEvenSort(arr);
		for (int i=0; i < arr.length; i++)
			System.out.print(arr[i] + " ");

		System.out.println();
	}
}

