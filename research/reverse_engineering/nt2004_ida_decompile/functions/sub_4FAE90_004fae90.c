char __thiscall sub_4FAE90(float *this)
{
  int v1; // esi

  if ( this[38] + 30.0 <= dbl_7DA9D0 )
  {
    v1 = 0;
    if ( (int)NumOfElements <= 0 )
      return 1;
    while ( sub_4DD970((float **)(dword_75AAD0[v1] + 20836), 0.0) )
    {
      if ( ++v1 >= (int)NumOfElements )
        return 1;
    }
  }
  return 0;
}
