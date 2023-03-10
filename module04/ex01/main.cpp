/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:58:04 by gsever            #+#    #+#             */
/*   Updated: 2023/03/03 15:25:28 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ANIMAL_COUNT 6

static void	JustSelfTestForAllocationLoopHalf( void )
{
	Animal	*_animals[ANIMAL_COUNT];
	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		std::cout << B_RED "HalfTEST[" << i << "] ~~~~~~~~~~~~~~" END\
			<< std::flush << std::endl;
		std::cout << B_GREEN "Leaks Before: " << std::flush;
		system("leaks AnimalBrain | grep 'leaked bytes'");
		std::cout << END << std::flush;
		if (i % 2 == 0)
			_animals[i] = new Dog();
		else
			_animals[i] = new Cat();
		std::cout << B_GREEN "Leaks After: " << std::flush;
		system("leaks AnimalBrain | grep 'leaked bytes'");
		std::cout << END << std::flush << std::endl;
	}

	_animals[0]->getBrain().setIdea(0, "Foo");
	_animals[0]->getBrain().setIdea(1, "Bar");
	_animals[1]->getBrain().setIdea(0, "LHS");
	_animals[1]->getBrain().setIdea(1, "RHS");

	std::cout << "_animals[0]: " << _animals[0]->getType() << ": "\
		<< _animals[0]->getBrain().getIdea(0) << std::flush << std::endl;
	std::cout << "_animals[0]: " << _animals[0]->getType() << ": "\
		<< _animals[0]->getBrain().getIdea(1) << std::flush << std::endl;
	std::cout << "_animals[1]: " << _animals[1]->getType() << ": "\
		<< _animals[1]->getBrain().getIdea(0) << std::flush << std::endl;
	std::cout << "_animals[1]: " << _animals[1]->getType() << ": "\
		<< _animals[1]->getBrain().getIdea(1)\
		<< std::flush << std::endl << std::endl;

	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		std::cout << B_RED "HalfTEST[" << i << "] ~~Destructor~~" END\
			<< std::flush << std::endl;
		std::cout << B_GREEN "Leaks Before: " << std::flush;
		system("leaks AnimalBrain | grep 'leaked bytes'");
		std::cout << END << std::flush;
		delete _animals[i];
		std::cout << B_GREEN "Leaks After: " << std::flush;
		system("leaks AnimalBrain | grep 'leaked bytes'");
		std::cout << END << std::flush << std::endl;
	}
}

static void	JustSelfTestForAllocationLoop( void )
{
	// const Animal	*_animals[3] = { new Animal(), new Dog(), new Cat() };
	const Animal	*_animals[2] = { new Dog(), new Cat() };
	for (int a = 0; a < 2; a++)
	{
		std::cout << B_RED "------------------------" END << std::flush\
			<< std::endl << std::endl;
		std::cout << B_GREEN "Leaks Before: " << std::flush;
		system("leaks AnimalBrain | grep 'leaked bytes'");
		std::cout << END << std::flush;
		delete _animals[a];
		std::cout << B_GREEN "Leaks After: " << std::flush;
		system("leaks AnimalBrain | grep 'leaked bytes'");
		std::cout << END << std::flush;
	}
}

static void	JustSelfTestForAllocation( void )
{
	std::cout << YELLOW "*********** Default Animal Test Area ***********" END\
		<< std::flush << std::endl;
	// const Animal	*a1 = new Animal();
	// std::cout << "~~~~~~~~~~~~~ Animal Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	// std::cout << B_GREEN "Leaks: " << std::flush;
	// system("leaks AnimalBrain | grep 'leaked bytes'");
	// std::cout << END << std::flush;
	// delete a1;
	// std::cout << B_GREEN "Leaks: " << std::flush;
	// system("leaks AnimalBrain | grep 'leaked bytes'");
	// std::cout << END << std::flush;
	// std::cout << B_RED "-------- Animals Allocated Destroyed! ------\n" END\
	// 	<< std::flush << std::endl;
	const Animal	*d1 = new Dog();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ Dog Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete d1;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- Dog Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl;
	const Animal	*c1 = new Cat();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ Cat Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete c1;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- Cat Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl;
	const Dog		*doge = new Dog();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ doge Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete doge;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- Doge Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl;
	const Cat		*catge = new Cat();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ catge Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete catge;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- catge Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl << std::endl;

	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain");
	std::cout << END << std::flush;

	std::cout << "Creating but not allocated memory area." GREEN\
		<< std::flush << std::endl;
	const Animal	*animal1 = NULL;
	const Dog		*dog1 = NULL;
	const Cat		*cat1 = NULL;
	const Brain		*brain1 = NULL;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	delete animal1;
	delete dog1;
	delete cat1;
	delete brain1;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << END "Creating but not allocated memory area finished sir!."\
		<< std::flush << std::endl;
	std::cout << YELLOW "************************************************" END\
		<< std::flush << std::endl;
}

/**
 * @brief
 *
 * 	en;
		C++ virtual function:
- A C++ virtual function is a member function in the base class that you redefine in a derived class. It is declared using the virtual keyword.
- It is used to tell the compiler to perform dynamic linkage or late binding on the function.
- There is a necessity to use the single pointer to refer to all the objects of the different classes. So, we create the pointer to the base class that refers to all the derived objects. But, when base class pointer contains the address of the derived class object, always executes the base class function. This issue can only be resolved by using the 'virtual' function.
- A 'virtual' is a keyword preceding the normal declaration of a function.
- When the function is made virtual, C++ determines which function is to be invoked at the runtime based on the type of the object pointed by the base class pointer.

virtual means the the linkage will be dynamic not static
	Explaination:
	At the beginning, we had a statis relution of the function calls, It means that during the compilation, (the compiler) we already will know which function to call. And for this we use the type of the variable.
	The only way for the compiler to know the behavior of my object is by knowing its type. And we marked it as a Character type. and the compiler will assume that its a Character.
	Therefore, it uses the Character version of the function.
	It was a static link! means that during the compilation is determined it won't change later.
	However, during the compilation let assume that we don't want it as a Warriror, but as a Wizard.
	it may point on a Warrior once and on the Wizard once based on what the user input.
	Thanks to the virtual, the resulotion of the function call wil be dynamic. and it will be decided at runtime.

	When we call the member function, during the execution becauese it's a function with a dynamic link, it will look for the actual type of the object. It will walk
 through the inheritance tree to find the actual type.

	A virtual member function is called a method.
	The definition of a method is a member function which resulotion will be dynamic.

Rules of Virtual Function:

	- Virtual functions must be members of some class.
	- Virtual functions cannot be static members.
	- They are accessed through object pointers.
	- They can be a friend of another class.
	- A virtual function must be defined in the base class, even though it is not used.
	- The prototypes of a virtual function of the base class and all the derived classes must be identical. If the two functions with the same name but different prototypes, C++ will consider them as the overloaded functions.
	- We cannot have a virtual constructor, but we can have a virtual destructor.

*********************************************************************************************************

	tr;
C++ sanal i??levi:
- Bir C++ sanal i??levi, t??retilmi?? bir s??n??fta yeniden tan??mlad??????n??z temel s??n??ftaki bir ??ye i??levdir. virtual anahtar s??zc?????? kullan??larak bildirilir.
- Derleyiciye i??lev ??zerinde dinamik ba??lant?? veya ge?? ba??lama ger??ekle??tirmesini s??ylemek i??in kullan??l??r.
- Farkl?? s??n??flar??n t??m nesnelerine at??fta bulunmak i??in tek i??aret??iyi kullanma zorunlulu??u vard??r. B??ylece, t??m t??retilmi?? nesnelere at??fta bulunan temel s??n??f??n i??aret??isini yarat??yoruz. Ancak, temel s??n??f i??aret??isi t??retilmi?? s??n??f nesnesinin adresini i??erdi??inde, her zaman temel s??n??f i??levini y??r??t??r. Bu sorun yaln??zca 'sanal' i??levi kullan??larak ????z??lebilir.
- Bir 'sanal', bir i??levin normal bildiriminden ??nce gelen bir anahtar s??zc??kt??r.
- ????lev sanal yap??ld??????nda, C++ temel s??n??f i??aret??isi taraf??ndan i??aret edilen nesnenin t??r??ne g??re ??al????ma zaman??nda hangi i??levin ??a??r??laca????n?? belirler.


Sanal, ba??lant??n??n statik de??il dinamik olaca???? anlam??na gelir
     A????klama:
     Ba??lang????ta, i??lev ??a??r??lar??n??n statik bir ????z??m?? vard??, bu, derleme s??ras??nda (derleyici) hangi i??levi ??a????raca????m??z?? zaten bilece??imiz anlam??na gelir. Bunun i??in de de??i??kenin tipini kullan??yoruz.
     Derleyicinin nesnemin davran??????n?? bilmesinin tek yolu onun t??r??n?? bilmektir. Ve onu bir Karakter t??r?? olarak i??aretledik. ve derleyici onun bir Karakter oldu??unu varsayacakt??r.
     Bu nedenle, i??levin Karakter s??r??m??n?? kullan??r.
     Statik bir ba??lant??yd??! derleme s??ras??nda daha sonra de??i??meyece??i belirlenir anlam??na gelir.
     Ancak derleme s??ras??nda onu bir Sava?????? olarak de??il, bir Sihirbaz olarak istedi??imizi varsayal??m.
     kullan??c??n??n girdisine ba??l?? olarak bir Sava??????y?? bir kez ve Sihirbaz?? bir kez i??aret edebilir.
     Sanal sayesinde fonksiyon ??a??r??s??n??n sonucu dinamik olacakt??r. ve ??al????ma zaman??nda karar verilecektir.

     ??ye fonksiyonu ??a????rd??????m??zda y??r??tme s??ras??nda dinamik ba??lant??l?? bir fonksiyon oldu??u i??in nesnenin ger??ek tipini arayacakt??r. y??r??yecek
  ger??ek t??r?? bulmak i??in kal??t??m a??ac?? arac??l??????yla.

     Bir sanal ??ye i??levine y??ntem denir.
     Bir y??ntemin tan??m??, ????z??mlemenin dinamik olaca???? bir ??ye i??levdir.

Sanal ????lev Kurallar??:

     - Sanal i??levler bir s??n??f??n ??yesi olmal??d??r.
     - Sanal i??levler statik ??ye olamaz.
     - Nesne i??aret??ileri arac??l??????yla eri??ilir.
     - Ba??ka bir s??n??f??n arkada???? olabilirler.
     - Kullan??lmasa bile temel s??n??fta sanal bir i??lev tan??mlanmal??d??r.
     - Temel s??n??f??n ve t??m t??retilmi?? s??n??flar??n sanal i??levinin prototipleri ayn?? olmal??d??r. Ayn?? ada ancak farkl?? prototiplere sahip iki i??lev varsa, C++ bunlar?? a????r?? y??klenmi?? i??levler olarak kabul eder.
     - Sanal bir kurucumuz olamaz ama sanal bir y??k??c??m??z olabilir.

 * @return int
 */
int	main()
{
// This area for PDF's test.
	std::cout << GREEN "*********** Default Animal Test Area ************" END\
		<< std::flush << std::endl;
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	std::cout << "-------- Dog and Cat Created! ------"\
		<< std::flush << std::endl << std::endl;
	std::cout << "\n-------- Animals Destroying! ------"\
		<< std::flush << std::endl;
	delete j;// Should not create leak
	delete i;
	// std::cout << GREEN "Leaks: ";
	std::cout << B_GREEN "Leaks: " << std::flush;// Eger buraya std::flush yazmazsam "Leaks: " 'i terminalde calistirdigimiz leaks'ten sonra yazdiyor ve bir isime yaramiyor... :)
	system("leaks AnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << GREEN "************************************************" END\
		<< std::flush << std::endl;

// This area for allocating memory for inherited classes.
	JustSelfTestForAllocation();

// This area for test all class with loop.
	std::cout << std::endl << B_RED "[[[[[[[[[ Loop Started! ]]]]]]]]]]]" END\
		<< std::flush << std::endl;
	JustSelfTestForAllocationLoop();
// This area inside one loop both animals creating for N times.
	std::cout << std::endl << B_RED "[[[[[[[[[ Half Loop Started! ]]]]]]]]]]]" END\
		<< std::flush << std::endl;
	JustSelfTestForAllocationLoopHalf();
	return (0);
}