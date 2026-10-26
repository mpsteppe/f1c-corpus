stdiobuf *__thiscall stdiobuf::`scalar deleting destructor'(stdiobuf *this, char a2)
{
  stdiobuf::~stdiobuf(this);
  if ( (a2 & 1) != 0 )
    j__free(this);
  return this;
}
