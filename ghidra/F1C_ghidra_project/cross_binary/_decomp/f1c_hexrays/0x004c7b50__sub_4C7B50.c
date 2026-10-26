// f1c  0x004c7b50  size=118
int __thiscall sub_4C7B50(int this)
{
  int v2; // eax
  int v3; // eax
  char *v4; // ecx
  int result; // eax

  v2 = sub_415230((char ****)&dword_5EA5E8, (const char *)(this + 17952), this + 18196);
  *(_DWORD *)(this + 18588) = v2;
  if ( v2 < 0 )
  {
    v3 = dword_8AC394 + 1060 * *(_DWORD *)(this + 18584);
    if ( v3 )
    {
      v4 = *(char **)v3;
      if ( !*(_DWORD *)v3 )
        v4 = byte_5EA438;
      *(_DWORD *)(this + 18588) = sub_415230((char ****)&dword_5EA5E8, (const char *)(v3 + 188), (int)v4);
    }
  }
  result = sub_415550(&dword_5EA5E8, this + 18104);
  *(_DWORD *)(this + 18592) = result;
  return result;
}
