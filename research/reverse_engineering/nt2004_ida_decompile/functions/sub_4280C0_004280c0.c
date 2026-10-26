int __thiscall sub_4280C0(int this)
{
  if ( dword_75CBB0 != 7 )
    return *(_DWORD *)(16 * *(_DWORD *)(this + 24584) + this + 24516) & 8;
  return *(_DWORD *)(this + 20892) == 3
      || *(_DWORD *)(this + 20848) >= dword_7D74B8
      || dword_75CBB4 == 8
      || *(_BYTE *)(this + 18910)
      || *(float *)(this + 19780) != 0.0
      || *(float *)(this + 19784) != 0.0
      || *(float *)(this + 19788) != 0.0;
}
