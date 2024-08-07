import { Disclosure} from '@headlessui/react'

export default function Navbar() {
  return (
    <Disclosure as="nav" className="bg-[#001C30] text-center">
      <a href='/'>
        <h1 className='text-5xl text-white '>Numerical</h1>
      </a>
    </Disclosure>
  )
}
