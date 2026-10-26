int *__thiscall sub_5F7FF0(_DWORD *this)
{
  int *result; // eax

  result = (int *)this[2344];
  this[2346] = result;
  if ( result )
  {
    for ( result = (int *)*result; result; result = (int *)*result )
    {
      *((_BYTE *)result + 809) = 0;
      result = (int *)this[2346];
      if ( !result )
        break;
      result = (int *)result[1];
      this[2346] = result;
      if ( !result )
        break;
    }
  }
  return result;
}
