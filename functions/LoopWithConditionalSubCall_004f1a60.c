void __thiscall sub_4F1A60(void *this, int a2, char a3)
{
  signed int i; // esi

  for ( i = 0; i < 4; ++i )
    sub_4F18C0((int)this, i, a2, 0);
  if ( a3 )
    TireBrushModelForceSolver((int)this, 0);
}
