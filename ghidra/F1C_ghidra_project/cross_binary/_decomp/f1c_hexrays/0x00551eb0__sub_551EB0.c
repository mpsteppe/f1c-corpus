// f1c  0x00551eb0  size=89
void __thiscall sub_551EB0(float *this, float a2)
{
  int v3; // eax

  if ( this[4] != a2 && a2 >= 0.0 && a2 <= 1.0 )
  {
    this[4] = a2;
    v3 = sub_587BDC(a2 * 32768.0);
    BinkSetVolume(*(_DWORD *)this, 0, v3);
  }
}
