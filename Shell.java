public class Shell {
    
    public static void shellSort(int[] arr){
        int n = arr.length;
        // Start with a large gap size and keep reducing it
        for(int gap=n/2; gap>0; gap /= 2){
            // Perform insertion sort on each sub-array defined by the gap sequence
            for(int i=gap;i<n;i++){
                int temp = arr[i];
                int j = i;
                // Compare elements that are 'gap' distance apart
                while (j>=gap && arr[j-gap]>temp){
                    arr[j] = arr[j-gap];
                    // Move the pointer to the previous element in the sub-array
                    j-=gap;
                }
                // Insert the temporary variable into the correct position
                arr[j] = temp; 
            }
        }
    } 
    public static void main (String[] args){
        int arr[] = {34, 2, 10, -9};

        shellSort(arr);
        for (int i=0; i < arr.length; i++)
            System.out.print(arr[i] + " ");

        System.out.println();
    }
    
}
