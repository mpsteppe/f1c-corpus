int sub_49DCF0()
{
  int result; // eax
  int v1; // edi
  int v2; // ebx
  int v3; // esi
  int v4; // [esp+8h] [ebp-138h]
  int v5; // [esp+1Ch] [ebp-124h]
  char Buffer[32]; // [esp+20h] [ebp-120h] BYREF
  char v7[256]; // [esp+40h] [ebp-100h] BYREF

  sub_4D0AC0(v4);
  result = dword_BE1CD0;
  v1 = 0;
  if ( dword_BE1CD0 > 0 )
  {
    v2 = 0;
    do
    {
      v3 = v2 + dword_BE1CD8;
      sprintf(Buffer, "%i:%06.3f", 0, 0.0);
      sprintf(
        v7,
        "%s, %s%s%s%s%i",
        (const char *)(v3 + 324),
        (const char *)(v3 + 260),
        (const char *)&word_6FD924,
        Buffer,
        (const char *)&word_6FD924,
        v5);
      sub_4D93B0(v7, 0, 0, 0, 0, 0, -1, -1, -1, -1);
      result = dword_BE1CD0;
      ++v1;
      v2 += 396;
    }
    while ( v1 < dword_BE1CD0 );
  }
  return result;
}
