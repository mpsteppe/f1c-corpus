char *__thiscall sub_51C050(unsigned __int8 **this)
{
  int v2; // edx
  char *result; // eax

  if ( this[217090] != this[217089] )
  {
    do
    {
      sub_51B2F0(this[217090]);
      v2 = (int)(this[217090] + 848);
      --*this;
      this[217090] = (unsigned __int8 *)v2;
    }
    while ( (unsigned __int8 *)v2 != this[217089] );
  }
  result = (char *)(this + 1);
  this[217091] = (unsigned __int8 *)(this + 1);
  this[217090] = (unsigned __int8 *)(this + 1);
  this[217089] = (unsigned __int8 *)(this + 1);
  return result;
}
