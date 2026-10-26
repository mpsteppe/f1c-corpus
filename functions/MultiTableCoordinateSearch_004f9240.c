int __stdcall sub_4F9240(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  int v5; // ebp
  int i; // edi
  int v8; // [esp+10h] [ebp-10h]
  int v9; // [esp+14h] [ebp-Ch] BYREF
  int v10; // [esp+18h] [ebp-8h] BYREF
  int v11; // [esp+1Ch] [ebp-4h] BYREF

  v8 = dword_8AFE6C;
  v4 = 0;
  if ( ShortComputation_9150() <= 0 )
    return -1;
  v5 = a1;
  while ( 1 )
  {
    if ( v4 )
    {
      if ( v4 == v8 )
        UtilityFunction_9160(0);
      else
        UtilityFunction_9160(v4);
    }
    for ( i = 0; i < ConditionalDispatch_9190(); ++i )
    {
      GlobalGuardedFieldReader(i, &a1, &v9, &v10, &v11);
      if ( a1 == v5 && v9 == a2 && v10 == a3 && v11 == a4 )
        break;
    }
    if ( i < ConditionalDispatch_9190() )
      break;
    if ( ++v4 >= ShortComputation_9150() )
      return -1;
  }
  return i;
}
