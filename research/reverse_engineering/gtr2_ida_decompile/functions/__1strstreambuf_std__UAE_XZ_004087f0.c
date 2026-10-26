void __thiscall std::strstreambuf::~strstreambuf(void **this)
{
  void **v1; // esi
  void **v2; // edi

  v1 = this;
  *this = &off_6F1C78;
  sub_408630(this);
  sub_407640();
  j__free(v1[8]);
  v1[8] = 0;
  v2 = v1 + 4;
  sub_407640();
  j__free(v1[5]);
  ++v1;
  v2[1] = 0;
  sub_407640();
  j__free(v1[1]);
  v1[1] = 0;
}
