#pragma once

#include <Crawler/Linker.hpp>
#include <Crawler/Worker.hpp>
#include <list>
#include <memory>

namespace Crawler
{
	class Application ;

	class CRAWLER_API WorkerManager
	{
		public :
			/// \brief Constructor
			/// \param application Reference to application object
			WorkerManager ( Application & application ) ;
			
			WorkerManager ( const WorkerManager & workerManager ) = delete ;
			WorkerManager ( WorkerManager && workerManager ) = delete ;
			WorkerManager & operator = ( const WorkerManager & workerManager ) = delete ;
			WorkerManager & operator = ( WorkerManager && workerManager ) = delete ;
			
			/// \brief Returns application
			/// \return Reference to application
			Crawler::Application & getApplication ( ) ;
			
			/// \brief Returns application
			/// \return Reference to application
			const Crawler::Application & getApplication ( ) const ;

			/// \brief Changes amount of worker
			/// \param amountOfWorker Value of amount of worker
			void setAmountOfWorker ( std::size_t amountOfWorker ) ;
			
			/// \brief Returns amount of worker
			/// \return Amount of worker
			std::size_t getAmountOfWorker ( ) const ;
			
			/// \brief Spawns a worker
			void spawnWorker ( ) ;
			
			/// \brief Despawns a worker
			void despawnWorker ( ) ;
			
			/// \brief Returns list of workers
			/// \return Reference to list of workers
			const std::list <std::unique_ptr <Crawler::Worker>> & getWorker ( ) const ;

		private :
			Crawler::Application & application ;
			std::list <std::unique_ptr <Crawler::Worker>> worker ;
			std::size_t amountOfWorker = 10 ;
	} ;
}
