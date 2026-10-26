int __thiscall sub_40F130(_DWORD *this)
{
  int result; // eax

  result = this[7];
  switch ( result )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      FloatDoubleCoordinateTransform(this + 3);
      if ( *this == -1 )
      {
        NestedLoopCall(this);
      }
      else
      {
        sub_410AF0(this);
        ArithmeticComparison_df90(this);
      }
      result = sub_4BE010(this);
      break;
    default:
      return result;
  }
  return result;
}

