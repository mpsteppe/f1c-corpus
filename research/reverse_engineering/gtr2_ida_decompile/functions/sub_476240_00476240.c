int *__thiscall sub_476240(int *this)
{
  int *result; // eax
  int *v2; // edx

  result = (int *)*this;
  if ( !*(_BYTE *)(*this + 21) )
  {
    v2 = (int *)result[2];
    if ( *((_BYTE *)v2 + 21) )
    {
      for ( result = (int *)result[1]; !*((_BYTE *)result + 21); result = (int *)result[1] )
      {
        if ( *this != result[2] )
          break;
        *this = (int)result;
      }
      *this = (int)result;
    }
    else
    {
      result = (int *)*v2;
      if ( !*(_BYTE *)(*v2 + 21) )
      {
        do
        {
          v2 = result;
          result = (int *)*result;
        }
        while ( !*((_BYTE *)result + 21) );
      }
      *this = (int)v2;
    }
  }
  return result;
}
