/**
 * @file   iterator.cc
 * @author
 *   chef <191201771@qq.com>
 *     -created 2017-06-01 09:57:25
 *     -initial release xxxx-xx-xx
 *
 */

#include <stdio.h>
#include <vector>

int main() {
  int arr[] = {2, 0, 1, 7, 0, 3, 0, 3};
  std::vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));
  std::vector<int>::iterator iter = vec.begin();
  for (; iter != vec.end(); iter++) {
    printf("%d ", *iter);
  }
  printf("\n");

  return 0;
}
