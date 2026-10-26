// f1c  0x0040d100  size=151
int __thiscall sub_40D100(_DWORD *this)
{
  int v2; // ecx
  int result; // eax

  v2 = this[6];
  if ( v2 )
  {
    switch ( dword_7CFDC4 )
    {
      case 1:
        sub_409440(v2, 1, 0, 1);
        result = sub_40CDE0(this, 1, 0);
        break;
      case 2:
        sub_409440(v2, 0, 0, 1);
        result = sub_40CDE0(this, 0, 0);
        break;
      case 3:
        sub_409440(v2, 3, 0, 1);
        result = sub_40CDE0(this, 3, 0);
        break;
      case 4:
        sub_409440(v2, 3, 0, 1);
        result = sub_40CDE0(this, 5, 0);
        break;
      default:
        sub_409440(v2, 2, 0, 1);
        result = sub_40CDE0(this, 2, 0);
        break;
    }
  }
  return result;
}
