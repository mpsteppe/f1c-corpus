void __thiscall sub_4A6E50(int this, float *a2)
{
  int v3; // eax

  v3 = *(_DWORD *)(this + 388);
  if ( !v3 || v3 == 4 )
  {
    if ( dword_7C5698 )
      return;
    if ( v3 == 4 )
      sub_4A6B80((_DWORD *)this);
  }
  if ( !*(_DWORD *)(*(_DWORD *)this + 13000) && !sub_4A6DB0((int *)this) )
  {
    if ( *(_DWORD *)(this + 388) == 2 && sub_4A5FA0((int *)this) && !*(_DWORD *)(*(_DWORD *)this + 13000) )
    {
      dword_7CE258 = 1;
      sub_4A5C80(this, 4);
    }
    goto LABEL_24;
  }
  switch ( *(_DWORD *)(this + 388) )
  {
    case 1:
      if ( *(float *)&a2 - *(float *)(this + 392) > 150.0 )
        sub_4A5C80(this, 0);
      goto LABEL_24;
    case 2:
      if ( !sub_4A5FA0((int *)this) )
        goto LABEL_24;
      *(_BYTE *)(this + 400) = 0;
      sub_4A5C80(this, 3);
      if ( *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) == *(_DWORD *)(this + 4) )
        sub_4D8840(2);
      break;
    case 3:
      if ( *(_BYTE *)(this + 400) )
      {
        sub_4A68B0(this, *(float *)&a2);
        goto LABEL_24;
      }
      break;
    default:
      goto LABEL_24;
  }
  sub_4A6200((float **)this, a2);
LABEL_24:
  if ( *(_BYTE *)(this + 384) && *(_DWORD *)(sub_4E9630(*(_DWORD *)this + 12) + 300) != 1 )
    sub_4A5F20((_BYTE *)this);
  if ( *(_BYTE *)(this + 428) )
  {
    if ( *(_DWORD *)(this + 388) != 3 )
    {
      *(_BYTE *)(this + 428) = 0;
      sub_40D410((int)&dword_5EA510);
    }
  }
}
