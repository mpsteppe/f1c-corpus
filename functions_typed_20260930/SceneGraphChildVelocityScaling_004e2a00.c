int __stdcall sub_4E2A00(int a1, float a2, char a3)
{
  int result; // eax
  int v5; // ebp
  int i; // esi

  do
  {
    result = SceneGraphChildCount(a1);
    v5 = result;
    for ( i = 0; i < v5; *(float *)(result + 248) = a2 * *(float *)(result + 248) )
    {
      result = LinkedListIndexedAccessor_c230(i++);
      *(float *)(result + 244) = a2 * *(float *)(result + 244);
    }
    if ( !a3 )
      break;
    a1 = *(_DWORD *)(a1 + 76);
  }
  while ( a1 );
  return result;
}

