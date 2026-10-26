char *__cdecl _cftof(_DWORD *a1, char *a2, size_t Size)
{
  int v4[4]; // [esp+4h] [ebp-2Ch] BYREF
  char Destination[24]; // [esp+14h] [ebp-1Ch] BYREF
  int v6; // [esp+2Ch] [ebp-4h]

  v6 = dword_912B08;
  sub_640B22(*a1, a1[1], (int)v4, Destination);
  _fptostr(&a2[v4[0] == 45], Size + v4[1], (int)v4);
  _cftof2(v4, a2, Size, 0);
  return a2;
}
