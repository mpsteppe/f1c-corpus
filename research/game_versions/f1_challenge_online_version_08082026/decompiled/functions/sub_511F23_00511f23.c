char *__cdecl sub_511F23(int a1, int *a2)
{
  char *result; // eax
  int v4; // edi
  int *v5; // ebx
  char *v6; // [esp+8h] [ebp-4h]
  int v7; // [esp+14h] [ebp+8h]

  result = (char *)sub_51234D(a1);
  v4 = *(_DWORD *)(a1 + 188);
  *(_DWORD *)(a1 + 192) = v4;
  if ( (int)result > 0 )
  {
    v6 = result;
    do
    {
      v5 = a2;
      if ( v4 )
      {
        v7 = v4;
        do
        {
          result = (char *)sub_511B7C(a1, *v5++, 0);
          --v7;
        }
        while ( v7 );
      }
      --v6;
    }
    while ( v6 );
  }
  return result;
}
