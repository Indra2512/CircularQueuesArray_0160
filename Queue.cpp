
/**
 * @mainpage dokumentation project Queue circular
 * 
 * @section introduction
 * project ini merupakan project struktur data 
 * menggunakan struktur data queue dengan pendekatan circular array.
 * 
 * @section operations
 * project ini memiliki beberapa operasi antara lain:
 * 1. insert
 * 2. delete
 * 3. display
 * 
 * @section Cara Penggunaan
 * berikut beberapa menu yang bisa digunakan:
 * 1. en queue
 * 2. de queue
 * 3. desplay
 * 4. exit
 * 
 * @author profile
 * @section
 * - Nama : M. Indra Ardian Saputra
 * - NIM : 20240140160
 * - KELAS : D
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Indra@umy.ac.id (c) 2025
 * 
 */
 
#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queues
 * 
 * 
 */
class Queues
{
    private:
        int FRONT; ///< variable private front untuk menyimpan posisi depan antrian
        int REAR; ///< variable private rear untuk menyimpan posisi belakang antrian
        int max = 5; ///< variable private max untuk menyimpan ukuran maximum antrian
        int queue_array[5]; ///< variable private queue_array untuk menyimpan elemen antrian 

    public:
        /**
         * @brief Construct a new Queues object
         * set default queues null
         * with front = -1 and rear = -1
         */
        Queues()
        {
            FRONT = 1;
            REAR = 1;
        }

        /**
         * @brief method untuk memasukkan data kedalam antrian
         * data dimasukkan dalam variable queue_array
         */
        void insert()
        {
            int num; ///< variable num untuk menyimpan data dengan bilangan bulat
            cout << "Enter a number: ";
            cin >> num;
            cout << endl;

            // 1. Cek apakah antrian penuh
            if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
            {
                cout << "\nQueue overflow\n"; //1.a
                return; //1. b
            }

            // 2. cek apakah antrian kosong
            if (FRONT == -1)
            {
                FRONT = 0; //2. a
                REAR = 0; //2. b
            }
            else
            {
                //jika REAR berada di posisi terakhir array, kembali ke awal array
                if (REAR == max - 1)
                    REAR = 0;
                else
                    REAR = REAR + 1;
            }
            queue_array[REAR] = num;
        }

        /**
         * @brief method untuk menghapus data dari dalam antrian  
         * data dihapus dari variable queue_array
         */
        void remove()
        {
            //cek apakah antrian kosong
            if (FRONT == -1)
            {
                cout << "Queue underflow\n";
                return;
            }
            cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

            //cek jika antrian hanya memiliki satu elemen
            if (FRONT == REAR)
            {
                FRONT = -1;
                REAR = -1;
            }
            else
            {
                //jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
                if (FRONT == max -1)
                    FRONT = 0;
                else
                    FRONT = FRONT + 1;
            }
        }

        /**
         * @brief method untuk menampilkan data dari antrian
         * data ditampilkan dari variable queue_array
         */
        void display()
        {
            int FRONT_posisition = FRONT; 
            int REAR_posisition = REAR; 

            //cek apakah antrian kosong
            if (FRONT == -1)
            {
                cout << "Queue is empty\n";
                return;
            }

            cout << "\nElements in the queue are...\n";

            //jika FRONT_posisition <= REAR_posisition, iterasi dari FRONT hingga REAR
            if (FRONT_posisition <= REAR_posisition)
            {
                while (FRONT_posisition <= REAR_posisition)
                {
                    cout << queue_array[FRONT_posisition] << "  ";
                    FRONT_posisition++;
                }

                FRONT_posisition = 0;

                // Iterasi dari awal array hingga REAR
                while (FRONT_posisition <= REAR_posisition)
                {
                    cout << queue_array[FRONT_posisition] << "  ";
                    FRONT_posisition++;
                }
                cout << endl;

            }
        }
};

/**
 * @brief main function untuk memanggil semua program
 * data di panggil
 */
int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete peration" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
                case '1':
                {

                    q.insert();
                    break;
                }
                case '2':
                {
                    q.remove();
                    break;
                }
                case '3':
                {
                    q.display();
                    break;
                }
                case '4':
                {
                    return 0;
                }
                default:
                {
                    cout << "invalid option!!" << endl;
                    break;
                }
            }
            
            
        }
            catch (exception &e)
            {
                 cout << "Check for the values entered." << endl;
            }
             

    
    }
}