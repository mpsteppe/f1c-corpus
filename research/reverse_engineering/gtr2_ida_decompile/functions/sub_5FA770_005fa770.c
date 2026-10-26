int __thiscall sub_5FA770(int this, int a2, int a3, char a4)
{
  int v5; // eax
  int v7; // eax
  int v8; // eax

  v5 = *(_DWORD *)(this + 340);
  if ( (v5 & 0x1000) != 0 )
    return (*(int (__stdcall **)(int))(this + 376))(a3);
  if ( v5 )
  {
    if ( (v5 & 0x20) != 0 && dword_FB40C0 && *(int *)(dword_FB40C0 + 768) > 0 )
    {
      v7 = **(_DWORD **)(a3 + 104);
      if ( (v7 & 0x4000000) != 0 )
      {
        sub_5F81B0((_DWORD *)this, a2, a3);
      }
      else if ( ((unsigned int)&dword_2000000 & v7) != 0 )
      {
        sub_5F7560(a2, a3);
      }
      else
      {
        sub_5F83F0((_DWORD *)this);
      }
    }
    v8 = *(_DWORD *)(this + 340);
    if ( (v8 & 8) != 0 )
    {
      sub_5F7460();
    }
    else if ( (v8 & 0x200) != 0 )
    {
      sub_5F72E0((_DWORD *)this, a2, (_DWORD *)a3);
    }
    if ( (*(_BYTE *)(this + 340) & 1) != 0 )
      sub_5F6FC0(this, a3, a2, (_DWORD *)a3, a4);
    if ( (*(_BYTE *)(this + 340) & 4) != 0 )
      sub_5F63B0(a3, a4);
  }
  return 1;
}
