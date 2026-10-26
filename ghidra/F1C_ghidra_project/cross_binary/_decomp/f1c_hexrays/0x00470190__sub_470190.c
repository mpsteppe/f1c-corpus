// f1c  0x00470190  size=160
int __thiscall sub_470190(void *this)
{
  int result; // eax
  int v2; // edi
  int v3; // ebx
  int v4; // esi
  int v5; // [esp+8h] [ebp-124h]
  char v6[32]; // [esp+Ch] [ebp-120h] BYREF
  _BYTE v7[256]; // [esp+2Ch] [ebp-100h] BYREF

  sub_489CB0(this);
  result = dword_8AC488;
  v2 = 0;
  if ( dword_8AC488 > 0 )
  {
    v3 = 0;
    do
    {
      v4 = v3 + dword_8AC490;
      sub_58815F(v6, "%i:%06.3f", 0, 0.0);
      sub_58815F(
        v7,
        "%s, %s%s%s%s%i",
        (const char *)(v4 + 324),
        (const char *)(v4 + 260),
        (const char *)&word_5C692C,
        v6,
        (const char *)&word_5C692C,
        v5);
      sub_489600(v7, 0, 0, 0, 0);
      result = dword_8AC488;
      ++v2;
      v3 += 396;
    }
    while ( v2 < dword_8AC488 );
  }
  return result;
}
