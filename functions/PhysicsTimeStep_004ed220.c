void __thiscall sub_4ED220(_DWORD *this, float a2)
{
  AccumulatorClamp((int)this, a2);
  if ( !this[3247] )
    PhysicsDampingScaleApplication(&dbl_7C7428, a2);
}
