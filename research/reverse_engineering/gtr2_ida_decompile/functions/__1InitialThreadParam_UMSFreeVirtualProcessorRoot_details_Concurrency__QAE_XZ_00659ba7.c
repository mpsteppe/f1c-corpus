void __thiscall Concurrency::details::UMSFreeVirtualProcessorRoot::InitialThreadParam::~InitialThreadParam(
        HGDIOBJ *this)
{
  if ( *this )
    DeleteObject(*this);
}
