char *__cdecl _cftog(_DWORD *a1, char *a2, signed int Size, int a4)
{
  int v4; // esi
  char *v5; // edi
  int v7; // [esp+Ch] [ebp-2Ch] BYREF
  int v8; // [esp+10h] [ebp-28h]
  char Destination[24]; // [esp+1Ch] [ebp-1Ch] BYREF
  int v10; // [esp+34h] [ebp-4h]

  v10 = dword_912B08;
  sub_640B22(*a1, a1[1], (int)&v7, Destination);
  v4 = v8 - 1;
  v5 = &a2[v7 == 45];
  _fptostr(v5, Size, (int)&v7);
  if ( v8 - 1 < -4 || v8 - 1 >= Size )
    return _cftoe2((int)&v7, a2, Size, a4, 1);
  if ( v4 < v8 - 1 )
    v5[strlen(v5) - 1] = 0;
  return _cftof2(&v7, a2, Size, 1);
}
