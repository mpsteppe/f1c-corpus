int __thiscall sub_593300(const char *this)
{
  const char *v1; // ebx
  unsigned int v2; // edi
  const char *v3; // ebp
  unsigned int v4; // esi
  int result; // eax
  int v6; // [esp+0h] [ebp-20h]
  int v7; // [esp+18h] [ebp-8h]
  const char *v8; // [esp+1Ch] [ebp-4h]

  v7 = off_9034A4;
  if ( dword_82F4A0 < 1023 )
  {
    ++dword_82F4A0;
    off_9034A4 += 848;
  }
  v1 = this + 28;
  v2 = strlen(this + 28);
  v8 = this + 60;
  v3 = this + 92;
  v4 = strlen(this + 60);
  *(float *)&v6 = dbl_FB1D18;
  sub_51B2A0((_DWORD *)v7, 2, 5, strlen(this + 92) + v4 + 1 + v2 + 2, 255, v6, 3);
  strcpy((char *)(v7 + 8), v1);
  strcpy((char *)(v2 + v7 + 9), v8);
  strcpy((char *)(v4 + v2 + 2 + v7 + 8), v3);
  return result;
}
