int __thiscall sub_4E0DB0(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // edi
  int v5; // ebx
  int result; // eax

  sub_4E0D00(this, (int)(this + 377));
  sub_4E0D00(this, (int)(this + 394));
  v2 = (int)(this + 98);
  v3 = 4;
  do
  {
    sub_4E0D00(this, v2 - 68);
    sub_4E0D00(this, v2);
    v2 += 296;
    --v3;
  }
  while ( v3 );
  v4 = (int)(this + 411);
  v5 = 8;
  do
  {
    result = sub_4E0D00(this, v4);
    v4 += 68;
    --v5;
  }
  while ( v5 );
  return result;
}
