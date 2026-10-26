// f1c  0x004bc2f0  size=38
void __thiscall sub_4BC2F0(int this, int a2)
{
  int v3; // eax

  v3 = *(_DWORD *)(this + 44);
  if ( v3 != a2 )
  {
    sub_419120((float *)dword_5EB978, *(int **)this, v3, a2);
    *(_DWORD *)(this + 44) = a2;
  }
}
