int __thiscall sub_50F890(int this)
{
  _BYTE *v2; // edi
  int v3; // ebx

  sub_524870(this + 8);
  sub_5099D0((char *)(this + 1808));
  sub_4C0090((_DWORD *)(this + 16504));
  v2 = (_BYTE *)(this + 19232);
  v3 = 4;
  do
  {
    sub_5099B0(v2);
    v2 += 28;
    --v3;
  }
  while ( v3 );
  sub_51F650(this + 19748);
  *(_DWORD *)(this + 16500) = -1;
  *(_DWORD *)(this + 18752) = 0;
  sub_50FB70(this);
  return this;
}
