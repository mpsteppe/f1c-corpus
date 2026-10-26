// f1c  0x004a4050  size=71
void __thiscall sub_4A4050(int this, float a2)
{
  int v2; // eax

  v2 = *(_DWORD *)(this + 120);
  if ( v2 )
  {
    if ( v2 == 1 )
      *(_DWORD *)(this + 132) = 0;
    else
      *(float *)(this + 132) = a2 + *(float *)(this + 132);
    sub_4A2840(this, *(float *)(this + 132));
  }
}
