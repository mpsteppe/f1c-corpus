int __thiscall sub_61DBD0(unsigned int *this)
{
  __int64 v1; // rax
  int v2; // esi

  v1 = *this;
  if ( (int)*this > 0 )
  {
    v2 = 0;
    do
    {
      LODWORD(v1) = v2 + this[1];
      *(double *)(v1 + 312) = 0.0;
      ++HIDWORD(v1);
      v2 += 584;
      *(double *)(v1 + 320) = 0.0;
      *(double *)(v1 + 328) = 0.0;
      *(double *)(v1 + 336) = 0.0;
      *(double *)(v1 + 344) = 0.0;
      *(double *)(v1 + 352) = 0.0;
      LODWORD(v1) = *this;
    }
    while ( SHIDWORD(v1) < (int)*this );
  }
  return v1;
}
