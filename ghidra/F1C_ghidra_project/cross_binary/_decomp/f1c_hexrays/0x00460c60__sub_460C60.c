// f1c  0x00460c60  size=75
int __thiscall sub_460C60(_DWORD *this)
{
  char *v1; // ebx
  char *v2; // edi
  _DWORD *v3; // esi
  int v4; // ebp
  int result; // eax

  v1 = (char *)(this + 4192);
  v2 = (char *)(this + 229);
  v3 = this + 3974;
  v4 = 104;
  do
  {
    *v3 = -1;
    sub_461480(v2);
    result = sub_4FFFA0(v1);
    ++v3;
    v2 += 140;
    v1 += 872;
    --v4;
  }
  while ( v4 );
  return result;
}
