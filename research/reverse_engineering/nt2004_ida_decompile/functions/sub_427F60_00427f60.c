int __thiscall sub_427F60(int this, int a2)
{
  int result; // eax

  result = *(_DWORD *)(this + 80);
  if ( !*(_DWORD *)(result + 25300) )
  {
    if ( a2 == 18 )
      *(float *)(this + 24032) = flt_7D74DC;
    else
      *(float *)(this + 24032) = (float)a2;
  }
  return result;
}
