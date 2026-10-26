int __thiscall sub_50FD30(int this, float *a2)
{
  int v3; // eax
  int v4; // eax
  int result; // eax

  v3 = *(_DWORD *)(this + 16500);
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      result = v4 - 1;
      if ( !result )
      {
        *(float *)(this + 17480) = *(float *)&a2;
        return sub_51CC60(*(float *)&a2);
      }
    }
    else
    {
      sub_4C2E00((int *)(this + 16504), a2);
      return sub_510210(a2);
    }
  }
  else
  {
    sub_4C2E00((int *)(this + 16504), a2);
    sub_4448C0((int *)&dbl_75E930, *(float *)&a2);
    *(float *)(this + 17480) = *(float *)&a2;
    return sub_50FDB0(this);
  }
  return result;
}
