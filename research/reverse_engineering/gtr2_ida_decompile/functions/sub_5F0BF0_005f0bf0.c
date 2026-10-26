int __thiscall sub_5F0BF0(int this)
{
  if ( (*(_BYTE *)(this + 16) & 1) != 0 )
    sub_5E4BF0((void *)this, *(_BYTE **)(this + 176));
  else
    sub_5E7F70((void *)this, *(_DWORD *)(this + 172));
  sub_5F0620((_DWORD *)this);
  return 0;
}
