// f1c  0x004ae750  size=671
int __thiscall sub_4AE750(int *this, int a2)
{
  int v3; // edx
  int *v4; // ecx
  int v5; // edx
  int v6; // edx
  int result; // eax
  int v8; // [esp-4h] [ebp-8h]

  v3 = this[1726];
  v4 = this + 1723;
  v8 = v3;
  v5 = this[1725];
  *v4 = a2;
  sub_47F1F0(v4, v5, v8);
  v6 = this[1723];
  result = 0;
  switch ( v6 )
  {
    case 1:
      this[3505] = 0;
      this[3506] = 52;
      this[3498] = 0;
      this[3499] = 51;
      this[3484] = 0;
      this[3485] = 30;
      this[3491] = 0;
      this[3492] = 44;
      this[3512] = 0;
      this[3513] = 56;
      this[3519] = 0;
      this[3520] = 184;
      this[295] = 1058642330;
      goto LABEL_8;
    case 2:
      this[3505] = 1;
      this[3506] = 1;
      this[3498] = 1;
      this[3499] = 2;
      this[3484] = 1;
      this[3485] = 4;
      this[3491] = 1;
      this[3492] = 3;
      this[3512] = 1;
      this[3513] = 13;
      this[3520] = 14;
      break;
    case 3:
      this[3505] = 1;
      this[3506] = 30;
      this[3498] = 1;
      this[3499] = 31;
      this[3484] = 1;
      this[3485] = 33;
      this[3491] = 1;
      this[3492] = 32;
      this[3512] = 1;
      this[3513] = 42;
      this[3520] = 43;
      break;
    default:
      goto LABEL_8;
  }
  this[3519] = 1;
LABEL_8:
  if ( this[1723] )
  {
    this[3533] = 0;
    this[3534] = 16;
    this[3631] = 0;
    this[3632] = 48;
    this[3617] = 0;
    this[3618] = 47;
    this[3624] = 0;
    this[3625] = 49;
    this[3603] = 0;
    this[3604] = 26;
    this[3610] = 0;
    this[3611] = 27;
    this[3596] = 0;
    this[3597] = 38;
    this[3645] = 0;
    this[3646] = 19;
    this[3540] = 0;
    this[3541] = 28;
    this[3547] = 0;
    this[3548] = 31;
    this[3554] = 0;
    this[3555] = 200;
    this[3561] = 0;
    this[3562] = 208;
    this[3568] = 0;
    this[3569] = 205;
    this[3575] = 0;
    this[3576] = 203;
    this[3659] = 0;
    this[3660] = 21;
    this[3722] = 0;
    this[3723] = 89;
    this[3652] = 0;
    this[3653] = 25;
    this[3582] = 0;
    this[3583] = 24;
    this[3589] = 0;
    this[3590] = 53;
  }
  return result;
}
