int __cdecl sub_512093(int *a1, int *a2, int *a3)
{
  int result; // eax
  int v4; // esi
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  result = (int)a1;
  v4 = 0;
  v6 = 0;
  v5 = 0;
  if ( a1 )
  {
    result = *a1;
    v6 = *a1;
  }
  if ( a2 )
    v4 = *a2;
  if ( a3 )
  {
    result = *a3;
    v5 = *a3;
  }
  if ( v6 )
    result = LargeStructPartialReset(v6, v4, v5);
  if ( v4 )
  {
    result = GuardedDelegate(v4);
    *a2 = 0;
  }
  if ( v5 )
  {
    result = GuardedDelegate(v5);
    *a3 = 0;
  }
  if ( v6 )
  {
    GuardedDelegate(v6);
    result = (int)a1;
    *a1 = 0;
  }
  return result;
}
