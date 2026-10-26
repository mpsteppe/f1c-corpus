int __thiscall sub_5840D0(int this, float a2)
{
  int result; // eax

  result = *(_DWORD *)(this + 14804);
  switch ( result )
  {
    case 0:
      sub_500C40();
      sub_457A50((int)&dbl_B66040, a2);
      *(float *)(this + 15932) = a2;
      result = sub_574810(this);
      break;
    case 1:
      sub_500C40();
      result = sub_57FB80(this, SLODWORD(a2));
      break;
    case 2:
      *(float *)(this + 15932) = a2;
      result = sub_578110();
      break;
    case 4:
      *(float *)(this + 15932) = a2;
      break;
    default:
      return result;
  }
  return result;
}
