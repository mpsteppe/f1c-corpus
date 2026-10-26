void __thiscall sub_519850(int *this, int a2)
{
  int v3; // eax
  _DWORD *v4; // ecx
  int *v5; // edx

  switch ( a2 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
      if ( !*(_DWORD *)(*this + 20896) )
        *(_DWORD *)(*this + 20896) = 6;
      sub_50B1D0(this + 452, a2);
      v3 = this[4125];
      this[4930] = 2;
      if ( v3 )
        goto LABEL_12;
      sub_441A90(&dbl_75E930, a2);
      nullsub_2(*this, a2);
      return;
    case 4:
      v4 = this + 452;
      v5 = this + 841;
      goto LABEL_8;
    case 5:
      v4 = this + 452;
      v5 = this + 858;
LABEL_8:
      sub_50AF50(v4, v5);
      sub_4C0B10(this + 4126, 1);
      if ( !this[4930] )
        this[4930] = 1;
      this[4739] = this[4743];
      sub_513830((int)this, 0);
      nullsub_2(*this, a2);
      return;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
      sub_50AF50(this + 452, &this[17 * a2 + 773]);
      goto LABEL_12;
    default:
LABEL_12:
      nullsub_2(*this, a2);
      return;
  }
}
