// f1c  0x005993eb  size=64
int __thiscall sub_5993EB(int this, int a2, char a3)
{
  int result; // eax
  int v5; // eax

  *(_DWORD *)(this + 44) = 0;
  *(_DWORD *)(this + 40) = a2;
  *(_BYTE *)(this + 48) = 32;
  result = sub_59A948();
  if ( !*(_DWORD *)(this + 40) )
  {
    v5 = *(_DWORD *)(this + 4);
    LOBYTE(v5) = v5 | 4;
    result = sub_59A5FE(v5, 0);
  }
  if ( a3 )
    return sub_59A8FA(this);
  return result;
}
